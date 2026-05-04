/**
* @file ErrorMacros.h
* @autor Alberto Sanchoyerto
* @fecha 2026
* @version 1.0
*
* @copyright
* Copyright (c) 2026 Alberto Sanchoyerto
*
* @license MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
*/
#pragma once

#include "Logger.h"

#include <sstream>

#define LOG_DEBUG(msg) \
    Logger::instancia().log(NivelLog::DEBUG, msg)

#define LOG_INFO(msg) \
    Logger::instancia().log(NivelLog::INFO, msg)

#define LOG_WARNING(msg) \
    Logger::instancia().log(NivelLog::WARNING, msg)

#define LOG_ERROR(msg) \
    Logger::instancia().log(NivelLog::ERROR, msg)
