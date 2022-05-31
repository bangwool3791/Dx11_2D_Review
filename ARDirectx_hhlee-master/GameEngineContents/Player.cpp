#include "Player.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineBase/GameEngineInput.h>

Player::Player()
	:TimeAngle(0.f)
{
}

Player::Player(const float4& _Pos, float Angle)
	:TimeAngle(0.f)
	, PosAngle(Angle)
{
	GetTransform().SetLocalPosition(_Pos);
	Pos = float4{ 1.f , 0, 0, 0 };
}

Player::~Player()
{
}

void Player::Start()
{

	// GetTransform().SetLocalScale({ 100, 100, 100 });


	{
		//여기서 생성한 랜더러가 TitleLog 트랜스폼을 부모로 가지며,
		//랜더러 안에서 월드 변환을 진행한다.
		RendererComponent = CreateComponent<GameEngineRenderer>();
		RendererComponent->GetTransform().SetLocalScale({ 100, 100, 100 });
		RendererComponent->GetTransform().SetLocalPosition({ 100, 100, 100 });
	}

	{
		GameEngineCamera* Camera = CreateComponent<GameEngineCamera>();
	}

	TimeAngle = 0.0f;
}

void Player::Update(float _DeltaTime)
{
	TimeAngle += _DeltaTime * 360.f;
	Pos += float4{ (float)(_DeltaTime * 1.f), 0.f, 0, 0};
	float4 Angle = Pos.VectorRotationToDegreeZAxis(Pos, PosAngle);
	GetTransform().SetLocalMove(Angle);
	//GetTransform().SetLocalRotation({ 0.0f , 0.0f, TimeAngle });
	RendererComponent->GetTransform().SetLocalRotation({ TimeAngle , TimeAngle, TimeAngle });
}

void Player::End()
{
	int a = 0;
}