package v1.data.providers;

import v1.data.providers.db.DbProvider;
import v1.data.providers.http.HttpProvider;

enum ProviderTypes {
    DB,
    HTTP
}

public class Providers {
    private DbProvider db = new DbProvider();
    private HttpProvider http = new HttpProvider();

    public <T extends Object> T get(ProviderTypes type) {
        if (type.getClass().getName() == DbProvider.class.getName()) {
            return (T) db;
        }
        if (type == ProviderTypes.HTTP) {
            return (T) http;
        }
        return null;
    }
}
