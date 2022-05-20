#include "GameEngineVertexBuffer.h"
#include <GameEngineBase/GameEngineString.h>


GameEngineVertexBuffer* GameEngineVertexBuffer::CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name /*= ""*/)
{
	std::string name = GameEngineString::ToUpperReturn(_Name);
	GameEngineVertexBuffer * NewMesh = new GameEngineVertexBuffer();
	//버텍스 버퍼를 안에서 정의하고 
	NewMesh->SetName(name);
	//대문자로 문자열을 정리한 string을 버텍스 버퍼의 문자열 안에 넣어준다.
	NewMesh->Vertexs = _Vertex;
	//버텍스 버퍼의 버퍼에 입력 파마리터로 받은 버텍스를 대입한다.
	return NewMesh;
}


void GameEngineVertexBuffer::Create(const std::string& _Name, const std::vector<float4>& _Vertex)
{
	//CreateRes를 통해 할당한 GameEngineVertexBuffer 포인터를 맵 안에 넣어준다.
	GameEngineVertexBuffer* NewMesh = CreateRes(_Vertex, _Name);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));

}

void GameEngineVertexBuffer::GameEngineVertexBuffer::Create(const std::vector<float4> _Vertex)
{
	GameEngineVertexBuffer* NewMesh = CreateRes(_Vertex);
	NamedRes.insert(std::make_pair(NewMesh->GetNameCopy(), NewMesh));
}