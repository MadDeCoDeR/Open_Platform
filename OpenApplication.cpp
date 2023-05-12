/*
Open Platform

Copyright(C) 2020 George Kalmpokis

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
#include"OpenApplication.h"
#include <mutex>

class OpenAppLocal : public OpenApp {
	virtual const char* GetLocale();
	virtual bool GetBranch(char* name);
	virtual bool GetCloudStats(unsigned long long* totalBytes, unsigned long long* availableBytes);
public:
	static OpenApp* getInstance(bool apiEnabled);
	OpenAppLocal() {
		apiEnabled = false;
	}
private:
	bool apiEnabled;
};

OpenAppLocal appinstance;

const char* OpenAppLocal::GetLocale()
{
	return "";
}

bool OpenAppLocal::GetBranch(char* name)
{
	return false;
}

bool OpenAppLocal::GetCloudStats(unsigned long long* totalBytes, unsigned long long* availableBytes)
{
	return false;
}

OpenApp* OpenAppLocal::getInstance(bool apiEnabled)
{
	appinstance.apiEnabled = apiEnabled;
	return &appinstance;
}

OpenApp* getAppInstance(bool apiEnabled)
{
	return OpenAppLocal::getInstance(apiEnabled);
}