#pragma once

#include <stdexcept>

#define expect(statement, failure_message) if(!(statement)){ throw std::runtime_error( failure_message ); }