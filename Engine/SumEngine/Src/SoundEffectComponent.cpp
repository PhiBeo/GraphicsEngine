#include "Precompiled.h"
#include "SoundEffectComponent.h"

using namespace SumEngine;
using namespace SumEngine::Audio;

void SoundEffectComponent::Initialize()
{
	ASSERT(!mFileName.empty(), "SoundEffectComponnent: no sound file loaded");
	mSoundId = SoundEffectManager::Get()->Load(mFileName);
}

void SoundEffectComponent::Terminate()
{
	Stop();
}

void SoundEffectComponent::Deserialize(const rapidjson::Value& value)
{
	if (value.HasMember("FileName"))
	{
		mFileName = value["FileName"].GetString();
	}
	if (value.HasMember("Looping"))
	{
		mLooping = value["Looping"].GetBool();
	}
}

void SoundEffectComponent::DebugUI()
{
	ImGui::PushID(mFileName.c_str());
	ImGui::Text(mFileName.c_str());
	if (ImGui::Button("Play"))
	{
		Play();
	}
	ImGui::SameLine();
	if (ImGui::Button("Stop"))
	{
		Stop();
	}
	ImGui::PopID();

}

void SoundEffectComponent::Play()
{
	SoundEffectManager::Get()->Play(mSoundId, mLooping);
}

void SoundEffectComponent::Stop()
{
	SoundEffectManager::Get()->Stop(mSoundId);
}
