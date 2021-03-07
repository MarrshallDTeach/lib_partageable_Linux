
#include <iostream>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	void *libComposant1;
	void *libComposant2;

	libComposant1 = dlopen (argv[1],RTLD_LAZY);

	libComposant2 = dlopen (argv[2],RTLD_LAZY);
	
	int (*composant1)(int, int)=(int (*)(int, int))dlsym(libComposant1, "_Z10composant1ii");
	
	int (*composant2)(int, int)=(int (*)(int, int))dlsym(libComposant2, "_Z10composant2ii");
	
	char *(*getComposant1Version)(void) = (char *(*)(void))dlsym(libComposant1, "_Z20getComposant1Versionv");
	
	int data1=3;
	int data2=5;
	int valeur1=composant1(data1,data2);

	int valeur2=composant2(data1,data2);

	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

	dlclose(libComposant1);
	dlclose(libComposant2);
}
