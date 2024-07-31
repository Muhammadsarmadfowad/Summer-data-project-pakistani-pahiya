#ifndef LOG_H
#define LOG_H

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
class Logger {
public:
    enum LogLevel {
        INFO,
        WARNING,
        ERROR
    };
    
    ///////////////////////////////////////////////
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    
    
    
    /////////////////////////////////////////////////////////
    inline void log(LogLevel level, const   string& message) {
          ofstream logFile("log.txt",   ios_base::app);
        if (logFile.is_open()) {
            logFile << currentDateTime() << " - " << logLevelToString(level) << " - " << message <<   endl;
            logFile.close();
        } else {
              cerr << "Unable to open log file" <<   endl;
        }
    }
    
    
    
    //////////////////////////////////////////////////
    
private:
    Logger() {}
      string currentDateTime() {
          time_t now =   time(nullptr);
        char buf[80];
          strftime(buf, sizeof(buf), "%Y-%m-%d %X",   localtime(&now));
        return buf;
    }
      string logLevelToString(LogLevel level) {
        switch (level) {
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }
    
    ////////////////////////////////////////////////
/////////////////////////
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

///////////////////////////////////////////////////////////////////////
struct LineFrequency {
    std::string line;
    int frequency;
};






//////////////////////////////
std::string extractRelevantData(const std::string& line) {
    size_t pos = line.find(" - ", line.find(" - ", line.find(" - ") ,line.find(" - ", line.find(" - ") + 1)+ 1) + 1);
    if (pos != std::string::npos) {
        return line.substr(pos + 3);
    }
    return "";
}


///////////////////////////////////
inline void sortLineFrequencies(LineFrequency* lineFrequencies, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (lineFrequencies[j].frequency < lineFrequencies[j + 1].frequency) {
                LineFrequency temp = lineFrequencies[j];
                lineFrequencies[j] = lineFrequencies[j + 1];
                lineFrequencies[j + 1] = temp;
            }
        }
    }
}
#define LOG_INFO(message) Logger::getInstance().log(Logger::INFO, message)
#define LOG_WARNING(message) Logger::getInstance().log(Logger::WARNING, message)
#define LOG_ERROR(message) Logger::getInstance().log(Logger::ERROR, message)
#endif // LOG_H
