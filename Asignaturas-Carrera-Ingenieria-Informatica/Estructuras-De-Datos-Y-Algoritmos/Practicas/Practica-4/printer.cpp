#include "printer.h"
#include <iostream>

Printer::Printer(int maxNumJobs, int maxNumPages) : maxNumJobs{maxNumJobs}, maxNumPages{maxNumPages} {}

PrintJob Printer::next()
{
    if (!data.empty())
    {
        data.at(0) = data.back();
        data.pop_back();
    }
}

int Printer::queueLength() const
{
    return data.size();
}

bool Printer::isEmpty() const
{
    if (data.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Printer::isFull() const
{
    if (maxNumJobs < data.size() || maxNumPages < plusPages)
    {
        std::cout << "Esta lleno";
        return true;
    }
    else
    {
        std::cout << "No esta lleno";
        return false;
    }
}

int Printer::queuePages() const
{
    return maxNumPages;
}

int Printer::left(int index) const
{
    return (index * 2 + 1);
}

int Printer::right(int index) const
{
    return (index * 2 + 2);
}

void Printer::heapify_down(int i)
{

    int idx_left = left(i);
    int idx_right = right(i);

    int idx_lowest = i;
    if (idx_left < this->queueLength() && data.at(idx_lowest) > data.at(idx_left))
    {
        idx_lowest = idx_left;
    }
    if (idx_right < this->queueLength() && data.at(idx_lowest) > data.at(idx_right))
    {
        idx_lowest = idx_right;
    }

    if (idx_lowest != i)
    {
        std::swap(data[i], data[idx_lowest]);
        heapify_down(idx_lowest);
    }
}

void Printer::pop()
{
    if (this->isEmpty())
    {
        return;
    }

    std::swap(data.at(0), data.at(this->queueLength() - 1));

    heapify_down(0);
}

bool Printer::push(const PrintJob &dato, bool force)
{
    plusPages = plusPages + dato.getPages();

    if (data.size() == 0)
    {
        data.push_back(dato);
    }
    if (maxNumJobs < data.size() || maxNumPages < plusPages)
    {
        force = false;
        std::cout << "Esta al maximo    ";
        plusPages = plusPages - dato.getPages();

        return force;
    }
    else
    {
        if (data.back().getPages() > dato.getPages())
        {
            data.pop_back();
        }
        force = true;
        data.push_back(dato);
        std::cout << "NO Esta al maximo";

        return force;
    }
}

std::vector<PrintJob> Printer::priorityQueueBubble_sort(std::vector<PrintJob> vectorWithoutPriority)
{
    for (int i = 0; i < vectorWithoutPriority.size() - 1; i++)
    {
        for (int k = 0; k < vectorWithoutPriority.size() - 1; k++)
        {
            if (vectorWithoutPriority[k].getPages() > vectorWithoutPriority[k + 1].getPages())
            {
                std::swap(vectorWithoutPriority[k], vectorWithoutPriority[k + 1]);
            }
            else if (vectorWithoutPriority[k].getPages() == vectorWithoutPriority[k + 1].getPages())
            {
                if (vectorWithoutPriority[k].getTimeStamp() > vectorWithoutPriority[k + 1].getTimeStamp())
                {
                    std::swap(vectorWithoutPriority[k], vectorWithoutPriority[k + 1]);
                }
            }
        }
    }

    return vectorWithoutPriority;
}
