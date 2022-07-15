
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "test-projectSystemComponent.h"

namespace test_project
{
    void test_projectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<test_projectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<test_projectSystemComponent>("test_project", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void test_projectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("test_projectService"));
    }

    void test_projectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("test_projectService"));
    }

    void test_projectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void test_projectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    test_projectSystemComponent::test_projectSystemComponent()
    {
        if (test_projectInterface::Get() == nullptr)
        {
            test_projectInterface::Register(this);
        }
    }

    test_projectSystemComponent::~test_projectSystemComponent()
    {
        if (test_projectInterface::Get() == this)
        {
            test_projectInterface::Unregister(this);
        }
    }

    void test_projectSystemComponent::Init()
    {
    }

    void test_projectSystemComponent::Activate()
    {
        test_projectRequestBus::Handler::BusConnect();
    }

    void test_projectSystemComponent::Deactivate()
    {
        test_projectRequestBus::Handler::BusDisconnect();
    }
}
