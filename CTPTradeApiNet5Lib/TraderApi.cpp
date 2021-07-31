#include "pch.h"
#include "TraderApi.h"

namespace PhoenixCTP
{
	CThostFtdcTraderApi* TraderApi::CreateFtdcTraderApi(System::String^ pszFlowPath)
	{
		const char* pszFlowPathChar = netString2ConstChar(pszFlowPath);
		return CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPathChar);
	}
}

