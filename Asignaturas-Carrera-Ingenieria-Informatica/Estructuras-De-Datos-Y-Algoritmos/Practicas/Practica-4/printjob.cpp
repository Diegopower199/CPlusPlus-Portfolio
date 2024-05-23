#include "printjob.h"

PrintJob::PrintJob(int timestamp, int pages, const std::string &title) : timestamp{timestamp}, nPages{pages}, title{title} {}

int PrintJob::getPages() const
{
    return nPages;
}

int PrintJob::getTimeStamp() const
{
    return timestamp;
}

bool PrintJob::operator<(const PrintJob &p) const
{
    if (nPages != p.nPages)
    {
        return (nPages > p.nPages);
    }
    else
    {
        return (timestamp > p.timestamp);
    }
}

bool PrintJob::operator>(const PrintJob &p) const
{
    if (nPages != p.nPages)
    {
        return (nPages < p.nPages);
    }
    else
    {
        return (timestamp < p.timestamp);
    }
}

bool PrintJob::operator==(const PrintJob &p) const
{
    if (nPages != p.nPages)
    {
        return (nPages == p.nPages);
    }
    else
    {
        return (timestamp == p.timestamp);
    }
}

std::ostream &operator<<(std::ostream &os, const PrintJob &job)
{
    os << "Tiempo para imprimir: " << job.timestamp << ", Numero de paginas para imprimir: " << job.nPages << ", El titulo del libro:  " << job.title << "\n";
    return os;
}
