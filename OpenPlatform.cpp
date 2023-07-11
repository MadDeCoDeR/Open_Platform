/*
Open Platform

Copyright(C) 2019 George Kalmpokis

Permission is hereby granted, free of charge, to any person obtaining a copy of this software
and associated documentation files(the "Software"), to deal in the Software without
restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// OpenPlatfom.cpp : Defines the exported functions for the DLL application.
//

#include "OpenPlatform.h"

class OPlatformLocal : public OPlatform
{
public:
	virtual const char* API_Name();
	virtual bool API_Init();
	virtual bool API_Init(const char* data);
	virtual void API_Shutdown();
	virtual OpenAchievement* openAchievement();
	virtual OpenDLC* openDLC();
	virtual OpenApp* openApp();
	virtual OpenInput* openInput();
	virtual const char* GetPlatformUserName();
	virtual void ShowUser( unsigned int id);
	virtual bool API_pump();
	virtual void SetNotificationsPosition(unsigned int x, unsigned int y);
	virtual unsigned long long CreateLobby(int type, int maxplayers);
	virtual bool SetAdditionalInfo(const char* key, const char* value);
	virtual bool IsPortable();
	virtual unsigned char GetBatteryLevel();
	virtual bool ShowFloatingTextBox(int type, int xpos, int ypos, int width, int height);
public:
	OPlatformLocal() {
		apiEnabled = false;
	}
private:
	bool apiEnabled;
};

OPlatformLocal opl;

#if __MWERKS__
#pragma export on
#endif
#if __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
extern "C" OPlatform* GetPlatformAPI()
{
#if __MWERKS__
#pragma export off
#endif

	return &opl;
}
#if __GNUC__ >= 4
#pragma GCC visibility pop
#endif

OPlatform* op = &opl;

const char* OPlatformLocal::API_Name()
{
	return "no_platform";
}

bool OPlatformLocal::API_Init() { return false; }
bool OPlatformLocal::API_Init(const char* data)
{
	return false;
}
void  OPlatformLocal::API_Shutdown() {}
OpenAchievement* OPlatformLocal::openAchievement()
{
	return getAchievementInstance(apiEnabled);
}
OpenDLC* OPlatformLocal::openDLC()
{
	return getDLCInstance(apiEnabled);
}
OpenApp* OPlatformLocal::openApp()
{
	return getAppInstance(apiEnabled);
}
OpenInput* OPlatformLocal::openInput()
{
	return getInputInstance(apiEnabled);
}
const char* OPlatformLocal::GetPlatformUserName() { return ""; }
void OPlatformLocal::ShowUser( unsigned int id) {}
bool OPlatformLocal::API_pump() { return false; }
void OPlatformLocal::SetNotificationsPosition(unsigned int x, unsigned int y) {}
unsigned long long OPlatformLocal::CreateLobby(int type, int maxplayers) { return 0; }

bool OPlatformLocal::SetAdditionalInfo(const char* key, const char* value)
{
	return false;
}

bool OPlatformLocal::IsPortable()
{
	return false;
}

unsigned char OPlatformLocal::GetBatteryLevel()
{
	return 0;
}

bool OPlatformLocal::ShowFloatingTextBox(int type, int xpos, int ypos, int width, int height)
{
	return false;
}
