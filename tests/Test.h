#pragma once

#include <vector>
#include <iostream>
#include <functional>

namespace test {
	class Test {
		public:
			Test() {}
			virtual ~Test() {}
			
			virtual void onUpdate(float deltaTime) {}
			virtual void onRender() {}
			virtual void onImGuiRender() {}
	};

	// in this class we dont use a pure virtual function because we want to be able to chose what functions we want to implement, if we had pure virtual functions we would have to implement all of the functons in the 'Test' base class
	class TestMenu : public Test {
		public:
			TestMenu(Test*& currentTestPointer);

			void onImGuiRender() override;
			
			template<typename T>
			void RegisterTest(const std::string& name) {
				std::cout << "Registering test: " << name << std::endl;								
				m_Tests.push_back(std::make_pair(name, []() { return new T(); }));
			}
			
		private:
			Test*& m_CurrentTest;
			std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;
	};
}
