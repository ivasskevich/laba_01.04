#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class AbstractDevice abstract
{
protected:
	string producer;

public:
	string GetProducer()
	{
		return this->producer;
	}
	void SetProducer(string producer)
	{
		this->producer = producer;
	}
	virtual AbstractDevice* Clone() abstract;
};

class Box : public AbstractDevice
{
	string color;
public:
	string GetColor()
	{
		return this->color;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	AbstractDevice* Clone() override
	{
		Box * box = new Box;
		*box = *this;
		return box;
	}
};

class Memory : public AbstractDevice
{
	int volume;
	string type;
public:
	string GetType()
	{
		return this->type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
	int GetVolume()
	{
		return this->volume;
	}
	void SetVolume(int volume)
	{
		this->volume = volume;
	}
	AbstractDevice* Clone() override
	{
		Memory * memory = new Memory;
		*memory = *this;
		return memory;
	}
};

class Hdd : public AbstractDevice
{
	int volume;
	string type;
public:
	string GetType()
	{
		return this->type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
	int GetVolume()
	{
		return this->volume;
	}
	void SetVolume(int volume)
	{
		this->volume = volume;
	}
	AbstractDevice* Clone() override
	{
		Hdd * hdd = new Hdd;
		*hdd = *this;
		return hdd;
	}
};

class Processor : public AbstractDevice
{
	int corecount;
	double frequency;
public:
	double GetFrequency()
	{
		return this->frequency;
	}
	void SetFrequency(double frequency)
	{
		this->frequency = frequency;
	}
	int GetCoreCount()
	{
		return this->corecount;
	}
	void SetCoreCount(int corecount)
	{
		this->corecount = corecount;
	}
	AbstractDevice* Clone() override
	{
		Processor * processor = new Processor;
		*processor = *this;
		return processor;
	}
};

class VideoCard : public AbstractDevice
{
	int volume;
public:
	int GetVolume()
	{
		return this->volume;
	}
	void SetVolume(int volume)
	{
		this->volume = volume;
	}
	AbstractDevice* Clone() override
	{
		VideoCard * videocard = new VideoCard;
		*videocard = *this;
		return videocard;
	}
};

class Mainboard : public AbstractDevice
{
	double busfrequency;
	VideoCard* videocard;
public:
	double GetBusFrequency()
	{
		return this->busfrequency;
	}
	void SetBusFrequency(double busfrequency)
	{
		this->busfrequency = busfrequency;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	AbstractDevice* Clone() override
	{
		Mainboard *newObj = new Mainboard;
		*newObj = *this;
		newObj->videocard = this->videocard != nullptr ? (VideoCard*) this->videocard->Clone() : nullptr;
		return newObj;
	}
};

class Web_Camera : public AbstractDevice
{
	string name;
public:
	string GetName()
	{
		return this->name;
	}
	void SetName(string n)
	{
		this->name = n;
	}
	AbstractDevice* Clone() override
	{
		Web_Camera* web_camera = new Web_Camera;
		*web_camera = *this;
		return web_camera;
	}
};

class Mouse : public AbstractDevice
{
	string name;
	int dpi;
public:
	string GetName()
	{
		return this->name;
	}
	void SetName(string n)
	{
		this->name = n;
	}
	int GetDPI()
	{
		return this->dpi;
	}
	void SetDPI(int n)
	{
		this->dpi = n;
	}
	AbstractDevice* Clone() override
	{
		Mouse* mouse = new Mouse;
		*mouse = *this;
		return mouse;
	}
};

class Prototype abstract
{
public:
	 virtual Prototype* Clone() abstract;
};

class PersonalComputer: public Prototype
{
	Box* box;
	Mainboard* mainboard;
	Processor* processor;
	VideoCard* videocard;
	vector<Memory*> memories;
	vector<Hdd*> hdd;
public:
	Box* GetBox()
	{
		return this->box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return this->processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	Mainboard* GetMainboard()
	{
		return this->mainboard;
	}
	void SetMainboard(Mainboard* mainboard)
	{
		this->mainboard = mainboard;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	vector<Memory*>& GetMemories()
	{
		return memories;
	}
	void AddMemory(Memory * m)
	{
		memories.push_back(m);
	}
	vector<Hdd*>& GetHdd()
	{
		return hdd;
	}
	void AddHdd(Hdd * hdd)
	{
		this->hdd.push_back(hdd);
	}
	Prototype* Clone() override
	{
		PersonalComputer *pc = new PersonalComputer;
		pc->box = this->box != nullptr ? (Box*)this->box->Clone(): nullptr;
		pc->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone(): nullptr;
		pc->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
		pc->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
		for(Memory* m : this->memories)
		{
			if (m != nullptr)
			{
				pc->AddMemory((Memory*)m->Clone());
			}
		}
		for (Hdd* h : this->hdd)
		{
			if (h != nullptr)
			{
				pc->AddHdd((Hdd*)h->Clone());
			}
		}		
		return pc;
	}
};

class MobilePhone : public Prototype
{
	Box* box;
	Mainboard* mainboard;
	Processor* processor;
	VideoCard* videocard;
	vector<Memory*> memories;
	vector<Hdd*> hdd;
	Web_Camera* web_camera;
public:
	Box* GetBox()
	{
		return this->box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return this->processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	Mainboard* GetMainboard()
	{
		return this->mainboard;
	}
	void SetMainboard(Mainboard* mainboard)
	{
		this->mainboard = mainboard;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	vector<Memory*>& GetMemories()
	{
		return memories;
	}
	void AddMemory(Memory* m)
	{
		memories.push_back(m);
	}
	vector<Hdd*>& GetHdd()
	{
		return hdd;
	}
	void AddHdd(Hdd* hdd)
	{
		this->hdd.push_back(hdd);
	}
	Web_Camera* GetWebCam()
	{
		return this->web_camera;
	}
	void SetWebCam(Web_Camera* web_camera)
	{
		this->web_camera = web_camera;
	}
	Prototype* Clone() override
	{
		MobilePhone* pc = new MobilePhone;
		pc->box = this->box != nullptr ? (Box*)this->box->Clone() : nullptr;
		pc->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone() : nullptr;
		pc->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
		pc->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
		for (Memory* m : this->memories)
		{
			if (m != nullptr)
			{
				pc->AddMemory((Memory*)m->Clone());
			}
		}
		for (Hdd* h : this->hdd)
		{
			if (h != nullptr)
			{
				pc->AddHdd((Hdd*)h->Clone());
			}
		}
		pc->web_camera = this->web_camera != nullptr ? (Web_Camera*)this->web_camera->Clone() : nullptr;

		return pc;
	}
};

class Laptop : public Prototype
{
	Box* box;
	Mainboard* mainboard;
	Processor* processor;
	VideoCard* videocard;
	vector<Memory*> memories;
	vector<Hdd*> hdd;
	Web_Camera* web_camera;
	Mouse* mouse;
public:
	Box* GetBox()
	{
		return this->box;
	}
	void SetBox(Box* box)
	{
		this->box = box;
	}
	Processor* GetProcessor()
	{
		return this->processor;
	}
	void SetProcessor(Processor* processor)
	{
		this->processor = processor;
	}
	Mainboard* GetMainboard()
	{
		return this->mainboard;
	}
	void SetMainboard(Mainboard* mainboard)
	{
		this->mainboard = mainboard;
	}
	VideoCard* GetVideoCard()
	{
		return this->videocard;
	}
	void SetVideoCard(VideoCard* videocard)
	{
		this->videocard = videocard;
	}
	vector<Memory*>& GetMemories()
	{
		return memories;
	}
	void AddMemory(Memory* m)
	{
		memories.push_back(m);
	}
	vector<Hdd*>& GetHdd()
	{
		return hdd;
	}
	void AddHdd(Hdd* hdd)
	{
		this->hdd.push_back(hdd);
	}
	Web_Camera* GetWebCam()
	{
		return this->web_camera;
	}
	void SetWebCam(Web_Camera* web_camera)
	{
		this->web_camera = web_camera;
	}
	Mouse* GetMouse()
	{
		return this->mouse;
	}
	void SetMouse(Mouse* mouse)
	{
		this->mouse = mouse;
	}
	Prototype* Clone() override
	{
		Laptop* pc = new Laptop;
		pc->box = this->box != nullptr ? (Box*)this->box->Clone() : nullptr;
		pc->mainboard = this->mainboard != nullptr ? (Mainboard*)this->mainboard->Clone() : nullptr;
		pc->processor = this->processor != nullptr ? (Processor*)this->processor->Clone() : nullptr;
		pc->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
		for (Memory* m : this->memories)
		{
			if (m != nullptr)
			{
				pc->AddMemory((Memory*)m->Clone());
			}
		}
		for (Hdd* h : this->hdd)
		{
			if (h != nullptr)
			{
				pc->AddHdd((Hdd*)h->Clone());
			}
		}
		pc->web_camera = this->web_camera != nullptr ? (Web_Camera*)this->web_camera->Clone() : nullptr;
		pc->mouse = this->mouse != nullptr ? (Mouse*)this->mouse->Clone() : nullptr;

		return pc;
	}
};

class PcPrototypes
{
	map<string, PersonalComputer*> pcprototypes;
public:
	PcPrototypes()
	{
		InitializePcPrototypes();
	}


	PersonalComputer* operator[](string key)
	{
		return  pcprototypes[key];
	}
	void InitializePcPrototypes()
	{
		pcprototypes["Home"] = CreateHomeConfig();
		pcprototypes["Office"] = CreateOfficeConfig();
		pcprototypes["Game"] = CreateGamerConfig();
	}

	PersonalComputer* CreateHomeConfig()
	{
		PersonalComputer* config = new PersonalComputer();

		Box* box = new Box();
		box->SetColor("Silver");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("ATI");
		mainboard->SetBusFrequency(800);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Intel");
		processor->SetCoreCount(2);
		processor->SetFrequency(3);
		config->SetProcessor(processor);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("ATI");
		videocard->SetVolume(1024);
		config->SetVideoCard(videocard);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("Samsung");
		hdd->SetType("SATA");
		hdd->SetVolume(500);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR2");
		memory->SetVolume(2);
		config->AddMemory(memory);

		return config;
	}

	PersonalComputer* CreateOfficeConfig()
	{
		PersonalComputer* config = new PersonalComputer();

		Box* box = new Box();
		box->SetColor("White");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("Albatron");
		mainboard->SetBusFrequency(800);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("nVidia");
		videocard->SetVolume(1024);
		mainboard->SetVideoCard(videocard);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("AMD");
		processor->SetCoreCount(1);
		processor->SetFrequency(1.8);
		config->SetProcessor(processor);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("LG");
		hdd->SetType("SATA");
		hdd->SetVolume(160);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR2");
		memory->SetVolume(1);
		config->AddMemory(memory);

		config->SetVideoCard(nullptr);

		return config;
	}

	PersonalComputer* CreateGamerConfig()
	{
		PersonalComputer* config = new PersonalComputer();

		Box* box = new Box();
		box->SetColor("Black");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("Asus");
		mainboard->SetBusFrequency(800);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Intel");
		processor->SetCoreCount(4);
		processor->SetFrequency(4);
		config->SetProcessor(processor);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("nVidia");
		videocard->SetVolume(1024);
		config->SetVideoCard(videocard);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("WD");
		hdd->SetType("SATA2");
		hdd->SetVolume(1024);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR2");
		memory->SetVolume(4);
		config->AddMemory(memory);

		return config;
	}
};

class PhonePrototypes
{
	map<string, MobilePhone*> phone_prototypes;
public:
	PhonePrototypes()
	{
		InitializePcPrototypes();
	}


	MobilePhone* operator[](string key)
	{
		return  phone_prototypes[key];
	}
	void InitializePcPrototypes()
	{
		phone_prototypes["HomePhone"] = CreateHomeConfig();
	}

	MobilePhone* CreateHomeConfig()
	{
		MobilePhone* config = new MobilePhone();

		Box* box = new Box();
		box->SetColor("Marengo");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("ATIE");
		mainboard->SetBusFrequency(2000);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Intel");
		processor->SetCoreCount(6);
		processor->SetFrequency(8);
		config->SetProcessor(processor);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("DEL");
		videocard->SetVolume(1024);
		config->SetVideoCard(videocard);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("Samsung");
		hdd->SetType("SSD");
		hdd->SetVolume(1024);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR4");
		memory->SetVolume(4);
		config->AddMemory(memory);

		Web_Camera* web_camera = new Web_Camera();
		web_camera->SetProducer("Samsung");
		web_camera->SetName("QWERTY");
		config->SetWebCam(web_camera);

		return config;
	}
};

class LaptopPrototypes
{
	map<string, Laptop*> phone_prototypes;
public:
	LaptopPrototypes()
	{
		InitializePcPrototypes();
	}

	Laptop* operator[](string key)
	{
		return  phone_prototypes[key];
	}
	void InitializePcPrototypes()
	{
		phone_prototypes["HomeLaptop"] = CreateHomeConfig();
	}

	Laptop* CreateHomeConfig()
	{
		Laptop* config = new Laptop();

		Box* box = new Box();
		box->SetColor("Marengo");
		config->SetBox(box);

		Mainboard* mainboard = new Mainboard();
		mainboard->SetProducer("ATIE");
		mainboard->SetBusFrequency(2000);
		mainboard->SetVideoCard(nullptr);
		config->SetMainboard(mainboard);

		Processor* processor = new Processor();
		processor->SetProducer("Intel");
		processor->SetCoreCount(6);
		processor->SetFrequency(8);
		config->SetProcessor(processor);

		VideoCard* videocard = new VideoCard();
		videocard->SetProducer("DEL");
		videocard->SetVolume(1024);
		config->SetVideoCard(videocard);

		Hdd* hdd = new Hdd();
		hdd->SetProducer("Samsung");
		hdd->SetType("SSD");
		hdd->SetVolume(1024);
		config->AddHdd(hdd);

		Memory* memory = new Memory();
		memory->SetType("DDR4");
		memory->SetVolume(4);
		config->AddMemory(memory);

		Web_Camera* web_camera = new Web_Camera();
		web_camera->SetProducer("Samsung");
		web_camera->SetName("QWERTY");
		config->SetWebCam(web_camera);

		Mouse* mouse = new Mouse();
		mouse->SetProducer("Lenovo");
		mouse->SetName("Marti_4_ROM");
		mouse->SetDPI(24000);
		config->SetMouse(mouse);

		return config;
	}
};

void PrintPc(PersonalComputer *pc)
{
	cout << "PC configuration: " << endl;
	cout << "Box: " << pc->GetBox()->GetColor() << endl;
	cout << "Mainboard: " << pc->GetMainboard()->GetProducer() << pc->GetMainboard()->GetBusFrequency() << " MHz" << endl;
	if (pc->GetMainboard()->GetVideoCard() != nullptr)
	{
		cout << "Integrated VideoCard: " << pc->GetMainboard()->GetVideoCard()->GetProducer()
			 << pc->GetMainboard()->GetVideoCard()->GetVolume() << " Mb" << endl;
	}
	cout << "Processor: " << pc->GetProcessor()->GetProducer()
		 << pc->GetProcessor()->GetFrequency() << " GHz "
		 << pc->GetProcessor()->GetCoreCount() << " core" << endl;
	cout << "Memories: ";
	for(Memory *m : pc->GetMemories())
	{
		cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
	}
	cout << "Hdds: ";
	for(Hdd *h : pc->GetHdd())
	{
		cout << h->GetProducer() <<"  " << h->GetType() << "  " << h->GetVolume() << " Gb\n";
	}
	
	if (pc->GetVideoCard() != nullptr)
	{
		cout << "VideoCard: ";
		cout << pc->GetVideoCard()->GetProducer() << "  " << pc->GetVideoCard()->GetVolume() << " Mb\n";
	}
}

void PrintPhone(MobilePhone* pc)
{
	cout << "Phone configuration: " << endl;
	cout << "Box: " << pc->GetBox()->GetColor() << endl;
	cout << "Mainboard: " << pc->GetMainboard()->GetProducer() << pc->GetMainboard()->GetBusFrequency() << " MHz" << endl;
	if (pc->GetMainboard()->GetVideoCard() != nullptr)
	{
		cout << "Integrated VideoCard: " << pc->GetMainboard()->GetVideoCard()->GetProducer()
			<< pc->GetMainboard()->GetVideoCard()->GetVolume() << " Mb" << endl;
	}
	cout << "Processor: " << pc->GetProcessor()->GetProducer()
		<< pc->GetProcessor()->GetFrequency() << " GHz "
		<< pc->GetProcessor()->GetCoreCount() << " core" << endl;
	cout << "Memories: ";
	for (Memory* m : pc->GetMemories())
	{
		cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
	}
	cout << "Hdds: ";
	for (Hdd* h : pc->GetHdd())
	{
		cout << h->GetProducer() << "  " << h->GetType() << "  " << h->GetVolume() << " Gb\n";
	}

	if (pc->GetVideoCard() != nullptr)
	{
		cout << "VideoCard: ";
		cout << pc->GetVideoCard()->GetProducer() << "  " << pc->GetVideoCard()->GetVolume() << " Mb\n";
	}

	if (pc->GetWebCam() != nullptr)
	{
		cout << "Web_camera: ";
		cout << pc->GetWebCam()->GetProducer() << "  " << pc->GetWebCam()->GetName() << "\n";
	}
}

void PrintLaptop(Laptop* pc)
{
	cout << "Laptop configuration: " << endl;
	cout << "Box: " << pc->GetBox()->GetColor() << endl;
	cout << "Mainboard: " << pc->GetMainboard()->GetProducer() << pc->GetMainboard()->GetBusFrequency() << " MHz" << endl;
	if (pc->GetMainboard()->GetVideoCard() != nullptr)
	{
		cout << "Integrated VideoCard: " << pc->GetMainboard()->GetVideoCard()->GetProducer()
			<< pc->GetMainboard()->GetVideoCard()->GetVolume() << " Mb" << endl;
	}
	cout << "Processor: " << pc->GetProcessor()->GetProducer()
		<< pc->GetProcessor()->GetFrequency() << " GHz "
		<< pc->GetProcessor()->GetCoreCount() << " core" << endl;
	cout << "Memories: ";
	for (Memory* m : pc->GetMemories())
	{
		cout << m->GetType() << "  " << m->GetVolume() << " Gb\n";
	}
	cout << "Hdds: ";
	for (Hdd* h : pc->GetHdd())
	{
		cout << h->GetProducer() << "  " << h->GetType() << "  " << h->GetVolume() << " Gb\n";
	}

	if (pc->GetVideoCard() != nullptr)
	{
		cout << "VideoCard: ";
		cout << pc->GetVideoCard()->GetProducer() << "  " << pc->GetVideoCard()->GetVolume() << " Mb\n";
	}

	if (pc->GetWebCam() != nullptr)
	{
		cout << "Web_camera: ";
		cout << pc->GetWebCam()->GetProducer() << "  " << pc->GetWebCam()->GetName() << "\n";
	}

	if (pc->GetMouse() != nullptr)
	{
		cout << "Web_camera: ";
		cout << pc->GetMouse()->GetProducer() << "  " << pc->GetMouse()->GetName() << "  " << pc->GetMouse()->GetDPI() << "\n";
	}
}

int main()
{
	while (true) {
		cout << "Enter config prototype name: ";
		string prototypeName;
		cin >> prototypeName;

		if (prototypeName == "0") {
			break;
		}
		PcPrototypes pc;
		PersonalComputer* prototype = pc[prototypeName];
		if (prototype != nullptr)
		{
			PersonalComputer* pc = dynamic_cast<PersonalComputer*>(prototype->Clone());
			PrintPc(pc);
		}
		else
		{
			cout << "Error: incorrect config name\n";
		}
	}

	while (true) {
		cout << "Enter config phone name: ";
		string prototypeName;
		cin >> prototypeName;

		if (prototypeName == "0") {
			break;
		}
		PhonePrototypes Phone;
		MobilePhone* prototype = Phone[prototypeName];
		if (prototype != nullptr)
		{
			MobilePhone* Phone = dynamic_cast<MobilePhone*>(prototype->Clone());
			PrintPhone(Phone);
		}
		else
		{
			cout << "Error: incorrect config name\n";
		}
	}

	while (true) {
		cout << "Enter config phone name: ";
		string prototypeName;
		cin >> prototypeName;

		if (prototypeName == "0") {
			break;
		}
		LaptopPrototypes laptop;
		Laptop* prototype = laptop[prototypeName];
		if (prototype != nullptr)
		{
			Laptop* laptop = dynamic_cast<Laptop*>(prototype->Clone());
			PrintLaptop(laptop);
		}
		else
		{
			cout << "Error: incorrect config name\n";
		}
	}
}