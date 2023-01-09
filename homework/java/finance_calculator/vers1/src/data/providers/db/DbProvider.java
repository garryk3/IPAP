package data.providers.db;

import org.sqlite.SQLiteConnection;

import data.interfaces.IDatabase;

public class DbProvider implements IDatabase {
    private SQLiteConnection connection;

    @Override
    public void open() {
        // TODO Auto-generated method stub
    }

}
