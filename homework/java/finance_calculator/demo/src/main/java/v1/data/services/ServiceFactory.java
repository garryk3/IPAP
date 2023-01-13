package v1.data.services;

import v1.data.interfaces.IRunnable;
import v1.data.services.db.DbService;
import v1.data.services.http.HttpService;

public class ServiceFactory implements IRunnable {
    private static ServiceFactory INSTANCE;
    private DbService db;
    private HttpService http;

    private ServiceFactory() {}

    public static ServiceFactory getInstance() {
        if(INSTANCE == null) {
            INSTANCE = new ServiceFactory();
        }
        return INSTANCE;
    }

    public void start () {
        getDb().initialize();
    }

    public void stop() {
        getDb().close();
    }

    public DbService getDb() {
        if(db == null) {
            db = new DbService();
        }
        return db;
    }

    public HttpService getHttp() {
        if(http == null) {
            http = new HttpService();
        }
        return http;
    }
}
