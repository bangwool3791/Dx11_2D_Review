#include "PlayLevel.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Player.h"
#include "Monster.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start() 
{
	if (false == GameEngineInput::GetInst()->IsKey("CamLeft"))
	{
		GameEngineInput::GetInst()->CreateKey("CamLeft", 'a');
		GameEngineInput::GetInst()->CreateKey("CamRight", 'd');
		GameEngineInput::GetInst()->CreateKey("CamUp", 'q');
		GameEngineInput::GetInst()->CreateKey("CamDown", 'e');
		GameEngineInput::GetInst()->CreateKey("CamForward", 'w');
		GameEngineInput::GetInst()->CreateKey("CamBack", 's');

		GameEngineInput::GetInst()->CreateKey("CamRotY+", 'r');
		GameEngineInput::GetInst()->CreateKey("CamRotY-", 't');

	}


	{
		m_pCamera = CreateActor<GameEngineCameraActor>();
		
		m_pCamera->GetTransform().SetLocalPosition({ 0.f, 0.f, -50.0f });
	}

	{
		m_pPlayer = CreateActor<Player>();
	}

	{
		//Monster* actor = CreateActor<Monster>();
		//actor->GetTransform().SetLocalPosition({ 100.0f, 0.0f, 500.0f });
	}


}
void PlayLevel::Update(float _DeltaTime) 
{
	//GetMainCameraActorTransform().SetLocalPosition(m_pPlayer->GetTransform().GetLocalPosition());

	if(true == GameEngineInput::GetInst()->IsPress("CamLeft"))
	{
		m_pPlayer->GetTransform().SetLocalMove(float4::LEFT * _DeltaTime);
	}

	if(true == GameEngineInput::GetInst()->IsPress("CamRight"))
	{
		m_pPlayer->GetTransform().SetLocalMove(float4::RIGHT * _DeltaTime);
	}
	if(true == GameEngineInput::GetInst()->IsPress("CamUp"))
	{
		GetMainCameraActorTransform().SetLocalMove(float4::UP * 100 * _DeltaTime);
	}
	if(true == GameEngineInput::GetInst()->IsPress("CamDown"))
	{
		GetMainCameraActorTransform().SetLocalMove(float4::DOWN * 100 * _DeltaTime);
	}

	if(true == GameEngineInput::GetInst()->IsPress("CamForward"))
	{
		GetMainCameraActorTransform().SetLocalMove(float4::FORWARD * 100 * _DeltaTime);
	}
	if(true == GameEngineInput::GetInst()->IsPress("CamBack")) 
	{
		GetMainCameraActorTransform().SetLocalMove(float4::BACK * 100 * _DeltaTime);
	}

	static float4 Rot = { 0.0f, 0.0f, 0.0f };
	if (true == GameEngineInput::GetInst()->IsPress("CamRotY+"))
	{
		Rot.y += 360.0f * _DeltaTime;

		if (360.f < Rot.y)
		{
			Rot.y -= 360.f;
		}
	}
	if (true == GameEngineInput::GetInst()->IsPress("CamRotY-"))
	{
		Rot.y -= 360.0f * _DeltaTime;
	
		if (-360.f > Rot.y)
		{
			Rot.y += 360.f;
		}
	}

	m_PlayerDir = m_pPlayer->GetTransform().GetLocalPosition() - GetMainCameraActorTransform().GetLocalPosition();
	m_PlayerDir.Normalize();

	GetMainCamera()->View.View({ 0.f, 0.f, -50.0f }, m_PlayerDir, float4{ 0.f, 1.f, 0.f });
}
void PlayLevel::End() {}
