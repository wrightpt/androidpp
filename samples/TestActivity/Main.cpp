#include "TestActivity.h"

int main(int argc, char* argv[])
{
    android::os::Looper::prepareMainLooper();

    com::example::TestActivity mainActivity;

    android::os::Looper::getMainLooper()->loop();
	return 0;
}
