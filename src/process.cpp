#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {
  this->user_ = LinuxParser::User(pid);
  this->command_ = LinuxParser::Command(pid);
}

// TODO: Return this process's ID
int Process::Pid() const { return this->pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  long system_jiffies = LinuxParser::Jiffies();
  long process_jiffies =
      static_cast<float>(LinuxParser::ActiveJiffies(this->Pid()));
  return process_jiffies / system_jiffies;
};

// TODO: Return the command that generated this process
string Process::Command() const { return this->command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(this->Pid()); }

// TODO: Return the user (name) that generated this process
string Process::User() const { return this->user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(this->Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& p) {
  Process p2 = p;
  return this->CpuUtilization() < p2.CpuUtilization();
}
