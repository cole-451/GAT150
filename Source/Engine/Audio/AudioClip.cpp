#include "EnginePCH.h"
#include "AudioClip.h"

namespace parabellum {

parabellum::AudioClip::~AudioClip()
{
    if(m_sound) m_sound->release(); //does NOT like releasing sounds.
}

bool parabellum::AudioClip::Load(const std::string& filename, audiosys& audiosystem)
{
    FMOD::Sound* sound = nullptr;
    FMOD_RESULT result = audiosystem.system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &m_sound);
    if (!audiosys::checkFMODResult(result))return false;

    return true;
}
}
