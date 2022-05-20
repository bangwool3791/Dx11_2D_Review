#include "GameEngineVertexBuffer.h"
#include <GameEngineBase/GameEngineString.h>


GameEngineVertexBuffer* GameEngineVertexBuffer::CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name /*= ""*/)
{
	std::string name = GameEngineString::ToUpperReturn(_Name);
	GameEngineVertexBuffer * NewMesh = new GameEngineVertexBuffer();
	//���ؽ� ���۸� �ȿ��� �����ϰ� 
	NewMesh->SetName(name);
	//�빮�ڷ� ���ڿ��� ������ string�� ���ؽ� ������ ���ڿ� �ȿ� �־��ش�.
	NewMesh->Vertexs = _Vertex;
	//���ؽ� ������ ���ۿ� �Է� �ĸ����ͷ� ���� ���ؽ��� �����Ѵ�.
	return NewMesh;
}


void GameEngineVertexBuffer::Create(const std::string& _Name, const std::vector<float4>& _Vertex)
{
	//CreateRes�� ���� �Ҵ��� GameEngineVertexBuffer �����͸� �� �ȿ� �־��ش�.
	GameEngineVertexBuffer* NewMesh = CreateRes(_Vertex, _Name);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));

}

void GameEngineVertexBuffer::GameEngineVertexBuffer::Create(const std::vector<float4> _Vertex)
{
	GameEngineVertexBuffer* NewMesh = CreateRes(_Vertex);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));
}