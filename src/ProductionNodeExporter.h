#pragma once
#include "base.h"
#include "version.h"

template<class ProductionNodeClass>
class ProductionNodeExporter {
private:
	XnPredefinedProductionNodeType m_nodeType;
	const XnChar* m_strName;

public:
	ProductionNodeExporter(const XnChar* strName, XnPredefinedProductionNodeType nodeType)
	{
		m_nodeType = nodeType;
		m_strName = strName;
	}

	void GetDescription(XnProductionNodeDescription* pDescription)
	{
		pDescription->Type = m_nodeType;
		strcpy(pDescription->strVendor, VERSION_VENDOR);
		strcpy(pDescription->strName, m_strName);
		pDescription->Version.nMajor = VERSION_MAJOR;
		pDescription->Version.nMinor = VERSION_MINOR;
		pDescription->Version.nMaintenance = VERSION_MAINTENANCE;
		pDescription->Version.nBuild = VERSION_BUILD;
	}

	XnStatus EnumerateProductionTrees(xn::Context& context, xn::NodeInfoList& nodes, xn::EnumerationErrors* pErrors)
	{
		XnProductionNodeDescription desc;
		GetDescription(&desc);
		NodeInfoList neededNodes;
		return nodes.Add(desc, NULL, &neededNodes);
	}

	XnStatus Create(xn::Context& context, const XnChar* strInstanceName, const XnChar* strCreationInfo, xn::NodeInfoList* pNodes, const XnChar* strConfigurationDir, xn::ModuleProductionNode** ppInstance)
	{
		return InitImpl(context, strInstanceName, strCreationInfo, pNodes, strConfigurationDir, ppInstance);
	}

	void Destroy(xn::ModuleProductionNode* pInstance)
	{
		delete pInstance;
	}

protected:
	virtual XnStatus InitImpl(xn::Context& context, const XnChar* strInstanceName, const XnChar* strCreationInfo, xn::NodeInfoList* pNodes, const XnChar* strConfigurationDir, xn::ModuleProductionNode** ppInstance) = 0;

};
