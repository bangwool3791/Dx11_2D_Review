#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include "GameEngineLevel.h"
#include <math.h>

// Resources Header
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

void GameEngineCore::EngineResourcesInitialize()
{
	// 사각형 박스 에러용 텍스처 등등
	// 엔진수준에서 기본적으로 지원줘야 한다고 생각하는
	// 리소스들을 이니셜라이즈하는 단계

	{
		// 0       1

		//    원점
		
		// 3       2

		std::vector<float4> Vertex;
		Vertex.push_back(float4(-0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, 0.5f));
		Vertex.push_back(float4(0.5f, -0.5f));
		Vertex.push_back(float4(-0.5f, -0.5f));

		GameEngineVertexBuffer::Create("Rect", Vertex);
	}

	{
		// 0       1

		//    원점

		// 3       2

		std::vector<int> Index;

		// 첫번째 삼각형
		// 디폴트 생성자로 인자를 뒤에 추가해주는 요소 추가 함수.
		Index.resize(6);

		// 첫번째
		Index[0] = 0;
		Index[1] = 1;
		Index[2] = 2;

		// 두번째
		Index[3] = 0;
		Index[4] = 2;
		Index[5] = 3;

		GameEngineIndexBuffer::Create("Rect", Index);
	}

	{
		// 0       1

		//    원점

		// 3       2

		std::vector<float4> Vertex;
		Vertex.resize(24);
		// 앞면
		Vertex[0] = float4(-0.5f, 0.5f, 0.5f);
		Vertex[1] = float4(0.5f, 0.5f, 0.5f);
		Vertex[2] = float4(0.5f, -0.5f, 0.5f);
		Vertex[3] = float4(-0.5f, -0.5f, 0.5f);

		// 뒷면
		Vertex[4] = float4::VectorRotationToDegreeXAxis(Vertex[0], 180.f);
		Vertex[5] = float4::VectorRotationToDegreeXAxis(Vertex[1], 180.f);
		Vertex[6] = float4::VectorRotationToDegreeXAxis(Vertex[2], 180.f);
		Vertex[7] = float4::VectorRotationToDegreeXAxis(Vertex[3], 180.f);

		// 왼쪽
		Vertex[8] = float4::VectorRotationToDegreeYAxis(Vertex[0], -90.f);
		Vertex[9] = float4::VectorRotationToDegreeYAxis(Vertex[1], -90.f);
		Vertex[10] = float4::VectorRotationToDegreeYAxis(Vertex[2], -90.f);
		Vertex[11] = float4::VectorRotationToDegreeYAxis(Vertex[3], -90.f);

		// 오른쪽
		Vertex[12] = float4::VectorRotationToDegreeYAxis(Vertex[0], 90.f);
		Vertex[13] = float4::VectorRotationToDegreeYAxis(Vertex[1], 90.f);
		Vertex[14] = float4::VectorRotationToDegreeYAxis(Vertex[2], 90.f);
		Vertex[15] = float4::VectorRotationToDegreeYAxis(Vertex[3], 90.f);

		// 위
		Vertex[16] = float4::VectorRotationToDegreeXAxis(Vertex[0], -90.f);
		Vertex[17] = float4::VectorRotationToDegreeXAxis(Vertex[1], -90.f);
		Vertex[18] = float4::VectorRotationToDegreeXAxis(Vertex[2], -90.f);
		Vertex[19] = float4::VectorRotationToDegreeXAxis(Vertex[3], -90.f);

		// 아래
		Vertex[20] = float4::VectorRotationToDegreeXAxis(Vertex[0], 90.f);
		Vertex[21] = float4::VectorRotationToDegreeXAxis(Vertex[1], 90.f);
		Vertex[22] = float4::VectorRotationToDegreeXAxis(Vertex[2], 90.f);
		Vertex[23] = float4::VectorRotationToDegreeXAxis(Vertex[3], 90.f);


		GameEngineVertexBuffer::Create("Box", Vertex);
	}

	{
		std::vector<int> Index;
		Index.resize(36);
		for (int i = 0; i < 6; i++)
		{
			Index[0 + i * 6] = 0 + 4 * i;
			Index[1 + i * 6] = 1 + 4 * i;
			Index[2 + i * 6] = 2 + 4 * i;
			Index[3 + i * 6] = 0 + 4 * i;
			Index[4 + i * 6] = 2 + 4 * i;
			Index[5 + i * 6] = 3 + 4 * i;
		}

		GameEngineIndexBuffer::Create("Box", Index);
	}

}


void GameEngineCore::EngineResourcesDestroy()
{
	GameEngineVertexBuffer::ResourcesDestroy();
	GameEngineIndexBuffer::ResourcesDestroy();
}