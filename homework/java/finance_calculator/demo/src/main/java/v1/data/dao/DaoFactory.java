package v1.data.dao;

import v1.data.interfaces.IDatabase;
import v1.data.interfaces.IRunnable;
import v1.data.services.ServiceFactory;

public class DaoFactory implements IRunnable{
    private static DaoFactory INSTANCE;
    private IDatabase dbService;

    private DaoFactory() {}

    public static DaoFactory getInstance() {
        if(INSTANCE == null) {
            INSTANCE = new DaoFactory();
        }
        return INSTANCE;
    }

    public void start() {
        dbService = ServiceFactory.getInstance().getDb();
    }

    public CategoryDao getCategoryDao() {
        return new CategoryDao(dbService);
    }

    public void stop() {}
}
