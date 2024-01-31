/*
Open Platform

Copyright(C) 2023 George Kalampokis

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
#include "OpenMultiplayer.h"

class OpenMultiplayerLocal : public OpenMultiplayer {
	virtual void CreateLobby(int type, int maxplayers);
	virtual int CountLobbyUsers();
	virtual unsigned long long GetLobbyUserId(int index);
	virtual void JoinLobby(unsigned long long id);
	virtual void LeaveLobby();
	virtual bool SendPacket(unsigned long long userId, const void* data, unsigned int size);
	virtual bool hasAvailablePackets(int* size);
	virtual bool ReadPacket(void* data, int size, int* receivedSize, unsigned  long long* userId);
public:
	static OpenMultiplayer* getInstance(bool apiEnabled);
	OpenMultiplayerLocal() {
		apiEnabled = false;
	}
private:
	bool apiEnabled;
};

OpenMultiplayerLocal multiplayerinstance;

OpenMultiplayer* OpenMultiplayerLocal::getInstance(bool apiEnabled)
{
	multiplayerinstance.apiEnabled = apiEnabled;
	return &multiplayerinstance;
}

OpenMultiplayer* getMultiplayerInstance(bool apiEnabled)
{
	return OpenMultiplayerLocal::getInstance(apiEnabled);
}

void OpenMultiplayerLocal::CreateLobby(int type, int maxplayers)
{
}

int OpenMultiplayerLocal::CountLobbyUsers()
{
	return 0;
}

unsigned long long OpenMultiplayerLocal::GetLobbyUserId(int index)
{
	return 0;
}

void OpenMultiplayerLocal::JoinLobby(unsigned long long id)
{
}

void OpenMultiplayerLocal::LeaveLobby()
{
}

bool OpenMultiplayerLocal::SendPacket(unsigned long long userId, const void* data, unsigned int size)
{
	return false;
}

bool OpenMultiplayerLocal::hasAvailablePackets(int* size)
{
	return false;
}

bool OpenMultiplayerLocal::ReadPacket(void* data, int size, int* receivedSize, unsigned long long* userId)
{
	return false;
}
