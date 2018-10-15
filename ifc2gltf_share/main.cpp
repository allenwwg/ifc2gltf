#include <IfcFile.h>

#include "main.h"

namespace kagula
{
	int TestIfcParseLib(const char* fileName)
	{
		IfcParse::IfcFile file;
		if (!file.Init(fileName)) {
			std::cout << "Unable to parse .ifc file" << std::endl;
			return 1;
		}


		using namespace IfcSchema;

		IfcBuildingElement::list::ptr elements = file.entitiesByType<IfcBuildingElement>();

		std::cout << "Found " << elements->size() << " elements in " << fileName << ":" << std::endl;

		for (IfcBuildingElement::list::it it = elements->begin(); it != elements->end(); ++it) {

			const IfcBuildingElement* element = *it;
			std::string entity_message = element->entity->toString();
			std::cout << entity_message.c_str() << std::endl;

			if (element->is(IfcWindow::Class())) {
				const IfcWindow* window = (IfcWindow*)element;

				if (window->hasOverallWidth() && window->hasOverallHeight()) {
					const double area = window->OverallWidth()*window->OverallHeight();
					std::cout << "The area of this window is " << area << std::endl;
				}
			}

		}
		return 0;
	}


	int ParseIfcFile(const char* fileName,
		std::function<int(int, const char* message)> monitor,
		KagulaGLTFData &output)
	{
		return 0;
	}
}
