#include <iostream>
using namespace std;

// **硬件产品**
// 硬件产品 抽象产品类
class HardwareProduct
{
  public:
    virtual ~HardwareProduct();
    virtual void operation() = 0;

  protected:
    HardwareProduct();
};
// 硬件产品 - 打印机
class Printer : public HardwareProduct
{
  public:
    ~Printer();
    Printer();
    void operation();
};
// 硬件产品 - 复印机
class Copier : public HardwareProduct
{
  public:
    ~Copier();
    Copier();
    void operation();
};

// **软件产品**
// 软件产品 抽象产品类
class SoftwareProduct
{
  public:
    virtual ~SoftwareProduct();
    virtual void operation() = 0;

  protected:
    SoftwareProduct();
};
// 银行卡识别系统
class CardRecognitionSystem : public SoftwareProduct
{
  public:
    ~CardRecognitionSystem();
    CardRecognitionSystem();
    void operation();
};
// 身份证识别系统
class IdCardIdentificationSystem : public SoftwareProduct
{
  public:
    ~IdCardIdentificationSystem();
    IdCardIdentificationSystem();
    void operation();
};
// 驾照识别功能系统
class DriversLicenseIdentificationSystem : public SoftwareProduct
{
  public:
    ~DriversLicenseIdentificationSystem();
    DriversLicenseIdentificationSystem();
    void operation();
};

// **工厂**
// 科技公司抽象工厂类
class TechnologyCompany
{
  public:
    virtual ~TechnologyCompany();
    virtual HardwareProduct *create_hardware_product(int) = 0;
    virtual SoftwareProduct *create_software_product(int) = 0;

  protected:
    TechnologyCompany();
};

// 科技公司 硬件生产部门 工厂类
class HardwareDepartment : public TechnologyCompany
{
  public:
    ~HardwareDepartment();
    HardwareDepartment();
    HardwareProduct *create_hardware_product(int);
};

// 科技公司 软件生产部门 工厂类
class SoftwareDepartment : public TechnologyCompany
{
  public:
    ~SoftwareDepartment();
    SoftwareDepartment();
    SoftwareProduct *create_software_product(int);
};

int main()
{
    return 0;
}