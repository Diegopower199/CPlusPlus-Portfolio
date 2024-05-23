#ifndef PRINTJOB_H
#define PRINTJOB_H

#include <ostream>
#include <vector>

class PrintJob
{
public:
    PrintJob(int timestamp, int pages, const std::string &title);
    int getPages() const;
    int getTimeStamp() const;
    bool operator<(const PrintJob &) const;
    bool operator>(const PrintJob &) const;
    bool operator==(const PrintJob &) const;
    friend std::ostream &operator<<(std::ostream &os, const PrintJob &job);

protected:
    int nPages;
    int timestamp;
    std::string title;
};

std::ostream &operator<<(std::ostream &os, const PrintJob &job);

#endif
