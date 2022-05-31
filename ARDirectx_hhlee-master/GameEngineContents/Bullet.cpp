#include "Bullet.h"
#include "GameEngineCore/GameEngineRenderer.h"
#include "GameEngineCore/GameEngineCamera.h"

Bullet::Bullet() 
{
}

//Bullet::Bullet(float4 _Pos)
//	:TimeAngle(0.f)
//{
//	GetTransform().SetLocalPosition({ _Pos.x, _Pos.y, _Pos.z });
//}

Bullet::~Bullet() 
{
}

void Bullet::Start()
{
	// GetTransform().SetLocalScale({ 100, 100, 100 });

	{
		//���⼭ ������ �������� TitleLog Ʈ�������� �θ�� ������,
		//������ �ȿ��� ���� ��ȯ�� �����Ѵ�.
		RendererComponent = CreateComponent<GameEngineRenderer>();
		RendererComponent->GetTransform().SetLocalScale({ 100, 100, 100 });
		RendererComponent->GetTransform().SetLocalPosition({ 100, 100, 100 });
	}

	{
		GameEngineCamera* Camera = CreateComponent<GameEngineCamera>();
	}

	TimeAngle = 0.0f;
}

void Bullet::Update(float _DeltaTime)
{
	TimeAngle += _DeltaTime * 90.0f;

	static float4 Pos = float4{ _DeltaTime , 0, 0, 0 };
	Pos += float4{ _DeltaTime , -_DeltaTime, 0, 0 };
	GetTransform().SetLocalMove(Pos);
	//GetTransform().SetLocalRotation({ 0.0f , 0.0f, TimeAngle });
	RendererComponent->GetTransform().SetLocalRotation({ TimeAngle , TimeAngle, TimeAngle });
}

void Bullet::End()
{
	int a = 0;
}

