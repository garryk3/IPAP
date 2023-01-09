package v1.data.interfaces;

public interface IDatabase {
    public void open();

    public void open(String name);

    public void close();

    public int executeUpdate(String sql);

    public boolean executeQuery(String sql);
}
