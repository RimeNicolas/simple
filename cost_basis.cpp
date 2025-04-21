
class Lot {
public:
    double qty;
    double price;
    Lot(double qty, double price) : qty(qty), price(price) {};
};

Lot avg(std::vector<Lot> lots) {
    Lot avg(0,0);
    for (const auto el : lots) {
        avg.qty += el.qty;
        avg.price += el.qty * el.price;
    }
    avg.price /= avg.qty;
    Lot ans = {avg.qty, avg.price};
    return ans;
}

double redu_avg(std::vector<Lot>& lots, const Lot redu) {
    Lot tmp = avg(lots);
    double cg = (redu.price - tmp.price) * redu.qty;
    lots.clear();
    lots.push_back({tmp.qty - redu.qty, tmp.price});
    return cg;
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
