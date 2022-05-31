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

//월드 행렬을 계산한다.
void GameEngineTransform::CalculateWorld()
{
	//월드 행렬 계산 전 스케일 * 회전 * 위치를 곱해 로컬 행렬을 구한다. 
	LocalWorldMat = LocalScaleMat * LocalRotateMat * LocalPositionMat;

	//루트 트랜스폼이 아니라면
	if (nullptr != Parent)
	{
		// 로컬 * 부모 월드 = 월드 행렬
		WorldWorldMat = LocalWorldMat * Parent->GetWorldWorld();
	}
	//루트 트랜스폼이라면
	else 
	{
		//로컬 = 월드 
		WorldWorldMat = LocalWorldMat;
	}
}

//트랜스폼 부모, 자식을 할당하는 함수
void GameEngineTransform::PushChild(GameEngineTransform* _Child)
{
	_Child->Parent = this;
	Childs.push_back(_Child);
}