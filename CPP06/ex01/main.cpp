#include "Serializer.hpp"

int main() {
	Data originalData;
	originalData.name = "Esteves";
	originalData.age = 26;

	putStr(originalData.name + "\n", CYAN_BOLD);
	putNum(originalData.age, CYAN_BOLD);
	putStr("\n", RESET);

	uintptr_t raw = Serializer::serialize(&originalData);

	Data* deserializedData = Serializer::deserialize(raw);
	putStr(deserializedData->name + "\n", GREEN);
	putNum(deserializedData->age, GREEN);
	putStr("\n", RESET);
	return (0);
}