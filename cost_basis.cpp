
class Lot {
public:
    double qty;
    double price;
    double fees;
    Lot(double qty, double price, double fees = 0) : qty(qty), price(price), fees(fees) {};
};

Lot avg(std::vector<Lot> lots) {
    Lot avg(0,0,0);
    for (const auto el : lots) {
        avg.qty += el.qty;
        avg.price += el.qty * el.price;
        avg.fees += el.qty * el.fees;
    }
    avg.price /= avg.qty;
    avg.fees /= avg.qty;
    return Lot(avg.qty, avg.price, avg.fees);
}

double redu_avg(std::vector<Lot>& lots, const Lot redu) {
    Lot avg_lot = avg(lots);
    lots.clear();
    lots.push_back(Lot(avg_lot.qty - redu.qty, avg_lot.price, avg_lot.fees));
    return ((redu.price - avg_lot.price)  - avg_lot.fees) * redu.qty;
}

double redu_fifo(std::queue<Lot>& lots, Lot redu) {
    double cg(0);
    while (redu.qty > 0) {
        if (lots.front().qty <= redu.qty) {
            cg += (redu.price - lots.front().price) * lots.front().qty;
            redu.qty -= lots.front().qty;
            lots.pop();
        }
        else {
            cg += (redu.price - lots.front().price) * redu.qty;
            lots.front().qty -= redu.qty;
            redu.qty = 0;
        }
    }
    return cg;
}

double redu_lifo(std::stack<Lot>& lots, Lot redu) {
    double cg(0);
    while (redu.qty > 0) {
        if (lots.top().qty <= redu.qty) {
            cg += (redu.price - lots.top().price) * lots.top().qty;
            redu.qty -= lots.top().qty;
            lots.pop();
        }
        else {
            cg += (redu.price - lots.top().price) * redu.qty;
            lots.top().qty -= redu.qty;
            redu.qty = 0;
        }
    }
    return cg;
}
