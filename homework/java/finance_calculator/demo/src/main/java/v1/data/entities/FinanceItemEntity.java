package v1.data.entities;

import v1.data.interfaces.IEntity;

public class FinanceItemEntity implements IEntity {
    private int id;
    private int price;
    private String type;
    private String name;
    private String currency;

    public FinanceItemEntity(int id, String currency, String name, String type, int price) {
        this.id = id;
        this.name = name;
        this.type = type;
        this.currency = currency;
        this.price = price;
    }

    @Override
    public int getId() {
        return id;
    }

    public String getCurrency() {
        return currency;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public int getPrice() {
        return price;
    }
}
