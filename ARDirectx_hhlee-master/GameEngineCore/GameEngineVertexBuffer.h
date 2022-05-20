#pragma once
#include <vector>
#include <list>
#include <map>
#include <string>
#include <GameEngineCore/GameEngineRes.h>
#include <GameEngineBase/GameEngineMath.h>

class GameEngineVertexBuffer : public GameEngineRes<GameEngineVertexBuffer>
{
	friend GameEngineRes<GameEngineVertexBuffer>;
private:
	// constrcuter destructer
	GameEngineVertexBuffer() {};
	~GameEngineVertexBuffer() {};

	// delete Function
	GameEngineVertexBuffer(const GameEngineVertexBuffer& _Other) = delete;
	GameEngineVertexBuffer(GameEngineVertexBuffer&& _Other) noexcept = delete;
	GameEngineVertexBuffer& operator=(const GameEngineVertexBuffer& _Other) = delete;
	GameEngineVertexBuffer& operator=(GameEngineVertexBuffer&& _Other) noexcept = delete;

private :
	static GameEngineVertexBuffer* CreateRes(const std::vector<float4>& _Vertex, const std::string& _Name = "");
public :
	static void Create(const std::string& _Name, const std::vector<float4>& _Vertex);
	static void Create(const std::vector<float4> _Vertext);

protected:

private:

public:
	std::vector<float4> Vertexs;
};

