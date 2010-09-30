
#include <errno.h>
#include <pthread.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#define  LOG_TAG  "gps_fake"
#include <cutils/log.h>
#include <hardware_legacy/gps.h>

#define  GPS_FAKE_DEBUG  0

#if GPS_FAKE_DEBUG
#  define  D(...)   LOGD(__VA_ARGS__)
#else
#  define  D(...)   ((void)0)
#endif

/*****************************************************************/
/*****************************************************************/
/*****                                                       *****/
/*****       I N T E R F A C E                               *****/
/*****                                                       *****/
/*****************************************************************/
/*****************************************************************/


static int
fake_gps_init(GpsCallbacks* callbacks)
{
    return 0;
}

static void
fake_gps_cleanup(void)
{
}

static int
fake_gps_start()
{
    return 0;
}

static int
fake_gps_stop()
{
    return 0;
}

static int
fake_gps_inject_time(GpsUtcTime time, int64_t timeReference, int uncertainty)
{
    return 0;
}

static int
fake_gps_inject_location(double latitude, double longitude, float accuracy)
{
    return 0;
}

static void
fake_gps_delete_aiding_data(GpsAidingData flags)
{
}

static int fake_gps_set_position_mode(GpsPositionMode mode, int fix_frequency)
{
    return 0;
}

static const void*
fake_gps_get_extension(const char* name)
{
    return NULL;
}

static const GpsInterface fakeGpsInterface = {
    fake_gps_init,
    fake_gps_start,
    fake_gps_stop,
    fake_gps_cleanup,
    fake_gps_inject_time,
    fake_gps_inject_location,
    fake_gps_delete_aiding_data,
    fake_gps_set_position_mode,
    fake_gps_get_extension,
};

const GpsInterface* gps_get_fake_interface()
{
    return &fakeGpsInterface;
}

