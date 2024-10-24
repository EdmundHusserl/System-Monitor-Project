#include "processor.h"

#include <iomanip>
#include <sstream>
#include <string>

#include "linux_parser.h"

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  auto cpus = LinuxParser::CpuUtilization();
  std::string cpu_utilization = cpus.size() > 0 ? cpus[0] : "0";
  return std::stof(cpu_utilization);
};