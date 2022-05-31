#include "PlayLevel.h"
#include "Player.h"
#include "Enums.h"
#include "GameEngineCore/GEngine.h"
#include "GameEngineBase/GameEngineInput.h"
#include "GameEngineBase/GameEngineWindow.h"
#include "GameEngineBase/GameEngineMath.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{
}
void PlayLevel::Update(float _DeltaTime)
{
	GameEngineInput::GetInst()->Update(_DeltaTime);
	if(GetAsyncKeyState(VK_LBUTTON) < 0)
	{
		POINT mouse;
		GetCursorPos(&mouse);
		ScreenToClient(GameEngineWindow ::Get_hWnd(),  & mouse);
		float4 MouseVector = float4((float)mouse.x, (float)mouse.y, 0.f, 0.f);

		//Set Axis Window Client 
		//float Result = float4::DotDegree(MouseVector, float4{ (float)WindowSize::WindowX * 0.5f,
		//	(float)WindowSize::WindowY * 0.5f, 0.f });

		CreateActor<Player, GameObjectGroup, float4, float>(GameObjectGroup::Player,
			float4{ static_cast<float>(mouse.x), static_cast<float>(mouse.y), 0.f },
			0.f * -1.f);
	}
}
void PlayLevel::End() 
{
}
