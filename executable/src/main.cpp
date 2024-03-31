
#include "main.hpp"

#include "zmq.hpp"

// Make sure to change the namespace EXECUTABLE to something more specific
namespace lush::EXECUTABLE {

	// Any forward declerations?

	void print_args(int argc, char** argv) {

		std::cout << "args: ";
		for (int idx = 0; idx < argc; idx++) {
			std::cout << argv[idx] << " ";
		}
		std::cout << std::endl;
	}

}  // namespace lush::EXECUTABLE

int main(int argc, char** argv) {

	std::cout << "Hello World! Executable given " << argc << " arguments." << std::endl;

	lush::EXECUTABLE::print_args(argc, argv);

	std::cout << "ZMQ VERS: " << ZMQ_VERSION_MAJOR << "." << ZMQ_VERSION_MINOR << "." << ZMQ_VERSION_PATCH << std::endl;

	zmq::context_t myContext;
	zmq::socket_t mySocket(myContext, zmq::socket_type::push);
	mySocket.bind("inproc://test");
	const std::string_view myMessage = "Hello world!";
	mySocket.send(zmq::buffer(myMessage), zmq::send_flags::dontwait);

}