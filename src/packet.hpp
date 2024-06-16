#include <string>
#include <vector>



class Packet {
	
	public:
		Packet();
		Packet(const std::vector<uint8_t>& data);
		void setData(const std::vector<uint8_t>& data);

	private:
		std::vector<uint8_t> data;
		
};



