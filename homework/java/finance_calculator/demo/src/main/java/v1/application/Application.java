package v1.application;

import java.util.ArrayList;
import java.util.List;
import v1.data.dao.DaoFactory;
import v1.data.interfaces.IRunnable;
import v1.data.services.ServiceFactory;

public class Application {
    private final List<IRunnable> runnableServices = new ArrayList<IRunnable>();

    public void startServices() {
        System.out.println("Start Services!");
        if(runnableServices.isEmpty()) {
            runnableServices.add(ServiceFactory.getInstance());
            runnableServices.add(DaoFactory.getInstance());
        }

        for(IRunnable service: runnableServices) {
            service.start();
        }
    }

    public void stopServices() {
        System.out.println("Stop Services!");
        for(IRunnable service: runnableServices) {
            service.stop();
        }
    }

    public void run() {
        System.out.println("Run App!");
        startServices();
    }

    public void stop() {
        System.out.println("Stop App!");
        stopServices();
    }
}
