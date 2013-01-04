// Copyright (C) 2012 Jérôme Leclercq
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Core/Posix/ClockImpl.hpp>
#include <Nazara/Core/Error.hpp>
#include <ctime>
#include <sys/time.h>
#include <Nazara/Core/Debug.hpp>


bool NzClockImplInitializeHighPrecision()
{
    // No initialization needed
}

nzUInt64 NzClockImplGetMicroseconds()
{
	timeval clock;
    gettimeofday(&clock, nullptr);
    return static_cast<nzUInt64>(clock.tv_sec*1000000 + (clock.tv_nsec/1000));

}

nzUInt64 NzClockImplGetMilliseconds()
{
    timeval clock;
    gettimeofday(&clock, nullptr);
    return static_cast<nzUInt64>(clock.tv_sec*1000 + (clock.tv_nsec/1000000));
}
