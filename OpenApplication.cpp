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
	virtual const char* GetBranch();
	virtual bool GetCloudStats(unsigned long long* totalBytes, unsigned long long* availableBytes);
public:
	static OpenApp* getInstance(bool apiEnabled);
	OpenAppLocal(OpenApp const&) = delete;
	OpenAppLocal(OpenAppLocal const&) = delete;
	void operator=(OpenApp const&) = delete;
	void operator=(OpenAppLocal const&) = delete;
private:
	OpenAppLocal() {
		this->apiEnabled = false;
	}
	OpenAppLocal(bool apiEnabled);
	bool apiEnabled;
	static OpenAppLocal* instance;
	static std::mutex mutex;
};

OpenAppLocal* OpenAppLocal::instance = nullptr;
std::mutex OpenAppLocal::mutex;

const char* OpenAppLocal::GetLocale()
{
	return "";
}

const char* OpenAppLocal::GetBranch()
{
	return "";
}

bool OpenAppLocal::GetCloudStats(unsigned long long* totalBytes, unsigned long long* availableBytes)
{
	return false;
}

OpenApp* OpenAppLocal::getInstance(bool apiEnabled)
{
	if (instance == nullptr) {
		std::lock_guard<std::mutex> lock(mutex);
		if (instance == nullptr) {
			instance = new OpenAppLocal(apiEnabled);
		}
	}
	return instance;
}

OpenAppLocal::OpenAppLocal(bool apiEnabled)
{
	this->apiEnabled = apiEnabled;
}

OpenApp* getAppInstance(bool apiEnabled)
{
	return OpenAppLocal::getInstance(apiEnabled);
}