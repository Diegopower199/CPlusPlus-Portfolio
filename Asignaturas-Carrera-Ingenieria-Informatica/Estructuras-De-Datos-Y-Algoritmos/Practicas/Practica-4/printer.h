#ifndef PRINTER_H
#define PRINTER_H

#include "printjob.h"
#include <vector>

class Printer
{
public:
    Printer(int maxNumJobs, int maxNumPages);

    int queueLength() const;
    int queuePages() const;
    bool isEmpty() const;
    bool isFull() const;

    PrintJob next();
    bool push(const PrintJob &dato, bool force = false);

    void pop();

    std::vector<PrintJob> priorityQueueBubble_sort(std::vector<PrintJob> vectorWithoutPriority);

private:
    std::vector<PrintJob> data;
    int maxNumJobs;

    int plusPages = 0;
    int plusJobs;

    int maxNumPages;

    void heapify_down(int i);

    int left(int index) const;

    int right(int index) const;
};

#endif
