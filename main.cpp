#include <iostream>
#include <vector>
#include<thread>
#include <future>

int global_processorID =0;
int global_processID   =0;

struct Process
{
    int cycles;
    int memory;
    int pid;
    Process()
    {
        pid = global_processID++;
        cycles = rand()%1000;
        memory = rand()%100;
    }
};

class Processor
{
public:
    Processor():processing(false)
    {

        this->processorID = global_processorID++;
    }
    bool processsing()
    {
        return processing;
    }
    void process(Process& process)
    {
        processing= true;

        std::async(std::launch::async,[&]
        {
            std::cout<<"Processor ID: "<<this->processorID<<" ,started Processing for cycles"<<process.cycles<<" ,process id :"<<process.pid<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(process.cycles*10));
            std::cout<<"Done Processing: "<<process.pid<<std::endl;
            processing=false;
        });
    }
    int processorID;
private:
    bool processing; 
};
class scheduler
{
public:

    void addPrcessor(Processor& aprocessor)
    {
        processor.push_back(&aprocessor);
    }

    void prcess(Process& process)
    {
        getNextAvilableProcessor()->process(process);
    }
    Processor* getNextAvilableProcessor()
    {
        for(auto& a : processor)
        {
            if(!a->processsing())
                return a;
        }
        std::cout<<"All processors are busy, Waiting for next avilable processor\n";
        while(true)
        {
            for(auto& a : processor)
            {
                if(!a->processsing())
                    return a;
            }
        }
    }

private:
    std::vector<Processor*> processor;

};

int main()
{

int i =257;
int*ptr = &i;
    std::vector<Process> processes(100);
    scheduler scheduler;
    Processor one;
    Processor two;
    Processor three;
    Processor four;
    scheduler.addPrcessor(one);
    scheduler.addPrcessor(two);
    scheduler.addPrcessor(three);
    scheduler.addPrcessor(four);

    for(auto& process : processes)
    {
        scheduler.prcess(process);
    };


}
