#pragma once

class ServerIocp;

using SessionSptr = std::shared_ptr<Session>;

class SessionPool
{

	enum
	{
		// �ӽ�
		IO_BUFFER_SIZE = 128 * 1024,
	};
	
	using SessionQueue = concurrency::concurrent_queue<std::shared_ptr<Session>>;
	
	SessionQueue					sessionQue_;
	Short							poolCount_;

public:
	SessionPool();
	~SessionPool();

	Bool							MakeSessionPool(ServerNetWorkDepartment* serverNetWorkDept, UShort poolCount, ReceiveProcessor* recvProcessor, SendProcessor* sendProcessor);
	
	SessionSptr						GetSession();
	
	Void							SessionReturns(std::shared_ptr<Session>& sessionPtr);
		
};