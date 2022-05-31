#include "PlayLevel.h"
#include "Player.h"
#include "Enums.h"
#include "GameEngineCore/GEngine.h"
#include "GameEngineBase/GameEngineInput.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{
	// GEngine::createActor
	for (float i = 0; i < 360.f; i += 35.f)
	{
		CreateActor<Player>(GameObjectGroup::Player,
			float4{ static_cast<float>(WindowSize::WindowX) * (float)0.5f, static_cast<float>(WindowSize::WindowY) * (float)0.5f, 0.f },
			i);
	}

	GameEngineInput::GetInst()->CreateKey("LButton", 'q');

}
void PlayLevel::Update(float _DeltaTime)
{
	GameEngineInput::GetInst()->Update(_DeltaTime);
	if (GameEngineInput::GetInst()->IsDown("LButton"))
	{
		for (float i = 0; i < 360.f; i += 35.f)
		{
			CreateActor<Player>(GameObjectGroup::Player,
				float4{ static_cast<float>(WindowSize::WindowX) * (float)0.5f, static_cast<float>(WindowSize::WindowY) * (float)0.5f, 0.f },
				i);
		}
	}
}
void PlayLevel::End() {}
