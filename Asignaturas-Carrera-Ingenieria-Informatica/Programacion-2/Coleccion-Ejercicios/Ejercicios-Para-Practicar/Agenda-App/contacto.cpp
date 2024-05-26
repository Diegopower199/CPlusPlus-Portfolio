#include "contacto.h"

Contacto::Contacto() : nombre(""), apellido1(""), telefono(""), email(""), nacimiento("") {}

Contacto::Contacto(std::string nom, std::string apell, std::string telef, std::string gmail, std::string fecha)
    : nombre(nom), apellido1(apell), telefono(telef), email(gmail), nacimiento(fecha) {}

std::string Contacto::getNombre() const { return nombre; }

void Contacto::setNombre(const std::string &value)
{
    if (value.empty())
        throw std::string{"No has introducido ningun nombre"};
    nombre = value;
}

std::string Contacto::getApellido1() const { return apellido1; }

void Contacto::setApellido1(const std::string &value)
{
    if (value.empty())
        throw std::string{"No has introducido ningun apellido valido"};
    apellido1 = value;
}

std::string Contacto::getTelefono() const { return telefono; }

void Contacto::setTelefono(const std::string &value)
{
    if (value.size() < 9)
        throw std::string{"Los telefonos tienen 9 digitos"};
    telefono = value;
}

std::string Contacto::getEmail() const { return email; }

void Contacto::setEmail(const std::string &value)
{
    if (value.empty())
        throw std::string{"No has introducido ningún email valido"};
    email = value;
}

std::string Contacto::getNacimiento() const { return nacimiento; }

void Contacto::setNacimiento(const std::string &value)
{
    if (value.empty())
        throw std::string{"No has introducido ninguna fecha valida"};
    nacimiento = value;
}

void Agenda::insertar(std::shared_ptr<Contacto> c1)
{
    agenda.push_back(c1);
}

void Agenda::borrar(const std::string &nomb_, const std::string &apell)
{
    for (auto it = agenda.begin(); it != agenda.end(); ++it)
    {
        if ((*it)->getNombre() == nomb_ && (*it)->getApellido1() == apell)
        {
            agenda.erase(it);
            break;
        }
    }
}

std::shared_ptr<Contacto> Agenda::findNom(const std::string &nomb_, const std::string &apell) const
{
    for (const auto &contacto : agenda)
    {
        if (contacto->getNombre() == nomb_ && contacto->getApellido1() == apell)
        {
            std::cout << "Contacto Encontrado\n";
            return contacto;
        }
    }
    std::cout << "Dicho contacto no se encuentra en la agenda\n";
    return nullptr;
}

std::shared_ptr<Contacto> Agenda::findAge(const std::string &nacimiento) const
{
    for (const auto &contacto : agenda)
    {
        if (contacto->getNacimiento() == nacimiento)
        {
            std::cout << "Contacto Encontrado\n";
            return contacto;
        }
    }
    std::cout << "Dicho contacto no se encuentra en la agenda\n";
    return nullptr;
}

std::shared_ptr<Contacto> Agenda::print(const std::string &fechas) const
{
    for (const auto &contacto : agenda)
    {
        if (contacto->getNacimiento() == fechas)
        {
            return contacto;
        }
    }
    std::cout << "No se encontró ningún contacto con esa fecha.\n";
    return nullptr;
}

std::vector<std::shared_ptr<Contacto>> Agenda::getAgenda() const
{
    return agenda;
}

void Agenda::setAgenda(const std::vector<std::shared_ptr<Contacto>> &agend)
{
    agenda = agend;
}

std::ostream &operator<<(std::ostream &os, const Contacto &c)
{
    os << "Nombre: " << c.getNombre() << "\n";
    os << "Apellido: " << c.getApellido1() << "\n";
    os << "Telefono: " << c.getTelefono() << "\n";
    os << "Email: " << c.getEmail() << "\n";
    os << "Fecha de nacimiento: " << c.getNacimiento() << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Agenda &ag)
{
    if (ag.getAgenda().empty())
    {
        os << "Agenda Vacia\n";
    }
    else
    {
        for (const auto &contacto : ag.getAgenda())
        {
            os << *contacto << "\n";
        }
    }
    return os;
}
