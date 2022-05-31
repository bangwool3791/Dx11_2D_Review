#include "GameEngineTransform.h"

GameEngineTransform::GameEngineTransform() 
	: LocalScale(float4::ONE)
	, LocalPosition(float4::ZERO)
	, LocalRotation(float4::ZERO)
	, Parent(nullptr)
{
}

GameEngineTransform::~GameEngineTransform() 
{
}

//���� ����� ����Ѵ�.
void GameEngineTransform::CalculateWorld()
{
	//���� ��� ��� �� ������ * ȸ�� * ��ġ�� ���� ���� ����� ���Ѵ�. 
	LocalWorldMat = LocalScaleMat * LocalRotateMat * LocalPositionMat;

	//��Ʈ Ʈ�������� �ƴ϶��
	if (nullptr != Parent)
	{
		// ���� * �θ� ���� = ���� ���
		WorldWorldMat = LocalWorldMat * Parent->GetWorldWorld();
	}
	//��Ʈ Ʈ�������̶��
	else 
	{
		//���� = ���� 
		WorldWorldMat = LocalWorldMat;
	}
}

//Ʈ������ �θ�, �ڽ��� �Ҵ��ϴ� �Լ�
void GameEngineTransform::PushChild(GameEngineTransform* _Child)
{
	_Child->Parent = this;
	Childs.push_back(_Child);
}