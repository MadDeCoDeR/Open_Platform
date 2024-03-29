
#include "OpenAchievement.h"
#include <mutex>

using namespace std;

class OpenAchievementLocal : public OpenAchievement {
	virtual bool GetAchievement(const char* name, bool* status);
	virtual const char* GetAchievementDevName(unsigned int id);
	virtual bool GetAchievementPercent(const char* name, unsigned int progress, unsigned int max);
	virtual bool UnlockAchievement(const char* name);
	virtual bool LockAchievement(const char* name);
	virtual const char* GetAchievementName(const char* name);
	virtual const char* GetAchievementDescription(const char* name);
	virtual bool GetAchievementHidden(const char* name);
public:
	static OpenAchievement* getInstance(bool apiEnabled);
	OpenAchievementLocal() {
		apiEnabled = false;
	}
private:
	bool apiEnabled;
};

OpenAchievementLocal achinstance;

bool OpenAchievementLocal::GetAchievement(const char* name, bool* status)
{
	return false;
}

const char* OpenAchievementLocal::GetAchievementDevName(unsigned int id)
{
	return "";
}

bool OpenAchievementLocal::GetAchievementPercent(const char* name, unsigned int progress, unsigned int max)
{
	return false;
}

bool OpenAchievementLocal::UnlockAchievement(const char* name)
{
	return false;
}

bool OpenAchievementLocal::LockAchievement(const char* name)
{
	return false;
}

const char* OpenAchievementLocal::GetAchievementName(const char* name)
{
	return "";
}

const char* OpenAchievementLocal::GetAchievementDescription(const char* name)
{
	return "";
}

bool OpenAchievementLocal::GetAchievementHidden(const char* name)
{
	return false;
}

OpenAchievement* OpenAchievementLocal::getInstance(bool apiEnabled)
{
	achinstance.apiEnabled = apiEnabled;
	return &achinstance;
}

OpenAchievement* getAchievementInstance(bool apiEnabled)
{
	return OpenAchievementLocal::getInstance(apiEnabled);
}
