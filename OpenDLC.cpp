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
#include"OpenDLC.h"
#include <mutex>

class OpenDLCLocal : public OpenDLC {
	virtual int CountDLCs();
	virtual OpenContent GetDLCByIndex(int index);
	virtual bool HasDLC(const char* id);
public:
	static OpenDLC* getInstance(bool apiEnabled);
	OpenDLCLocal(OpenDLC const&) = delete;
	OpenDLCLocal(OpenDLCLocal const&) = delete;
	void operator=(OpenDLC const&) = delete;
	void operator=(OpenDLCLocal const&) = delete;
private:
	OpenDLCLocal() {
		this->apiEnabled = false;
	}
	OpenDLCLocal(bool apiEnabled);
	bool apiEnabled;
	static OpenDLCLocal* instance;
	static std::mutex mutex;
};

OpenDLCLocal* OpenDLCLocal::instance = nullptr;
std::mutex OpenDLCLocal::mutex;

int OpenDLCLocal::CountDLCs()
{
	return 0;
}

OpenContent OpenDLCLocal::GetDLCByIndex(int index)
{
	return OpenContent();
}

bool OpenDLCLocal::HasDLC(const char* id)
{
	return false;
}

OpenDLC* OpenDLCLocal::getInstance(bool apiEnabled)
{
	if (instance == nullptr) {
		std::lock_guard<std::mutex> lock(mutex);
		if (instance == nullptr) {
			instance = new OpenDLCLocal(apiEnabled);
		}
	}
	return instance;
}

OpenDLCLocal::OpenDLCLocal(bool apiEnabled)
{
	this->apiEnabled = apiEnabled;
}

OpenDLC* getDLCInstance(bool apiEnabled)
{
	return OpenDLCLocal::getInstance(apiEnabled);
}
