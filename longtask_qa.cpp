#include <api/module.h>
#include <api/action.h>
#include <mgr/mgraccess.h>
#include <mgr/mgrlog.h>
#include <mgr/mgrtask.h>
 
MODULE("qa");
 
namespace {
using namespace isp_api;

class aLongTaskQA : public Action {
public:
        aLongTaskQA(): Action("longtask_qa", MinLevel(30)) { }
 
        void Execute(Session& ses) const {
                Trace();
		mgr_task::LongTask task(ses.Param("binary"), ses.Param("id"), ses.Param("queue"));
		task.Start();
        }
};

 
MODULE_INIT(longtask_qa, "") {
	new aLongTaskQA();
 
}
 
}
