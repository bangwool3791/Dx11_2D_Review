#include "Player.h"
#include <GameEngineCore/GameEngineRenderer.h>
Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	{
		GameEngineRenderer* RendererTest = CreateComponent<GameEngineRenderer>();
		RendererTest->GetTransform().SetLocalScale({ 100, 100, 100 });
		RendererTest->GetTransform().SetLocalPosition(float4{ 1280.f * 0.7f, 780.f * 0.5f });
	}
}


