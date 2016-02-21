#include <nan.h>

class TestAsyncWorker : public Nan::AsyncWorker
{
public:
	TestAsyncWorker(Nan::Callback *callback)
		: Nan::AsyncWorker(callback) {}
	~TestAsyncWorker(){}
	void Execute(){}
protected:
	void HandleOKCallback()
	{
		Nan::HandleScope scope;
		v8::Local<v8::Value> argv[2];
		argv[0] = Nan::Undefined();
		argv[1] = Nan::New("hello world").ToLocalChecked();
		callback->Call(2, argv);
	}
};

void RunCallback(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  // v8::Local<v8::Function> cb = info[0].As<v8::Function>();
  // const unsigned argc = 1;
  // v8::Local<v8::Value> argv[argc] = { Nan::New("hello world").ToLocalChecked() };
  // Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);

	v8::Local<v8::Function> callback = v8::Local<v8::Function>::Cast(info[0]);
	TestAsyncWorker* testWorker = new TestAsyncWorker(new Nan::Callback(callback));

      Nan::AsyncQueueWorker(testWorker);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  Nan::SetMethod(module, "exports", RunCallback);
}

NODE_MODULE(async, Init)
